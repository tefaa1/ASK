#include<bits/stdc++.h>
using namespace std;
#ifndef m_h
#define m_h
class login{
    string user,pass;
    public:
        login(){}
        login(string user,string pass):user(user),pass(pass){}
        void setuser(string s){
            user=s;
        }
        void setpass(string p){
            pass=p;
        }
        string getuser()const{
            return user;
        }
        string getpass()const{
            return pass;
        }
        bool checktheuser(){
            ifstream checkoo;
            checkoo.open("database of user name and pass.txt",ios::binary);
            string a;
            checkoo>>a;
            while(!checkoo.eof()){
                if(a==user){
                    checkoo.close();
                    return true;
                }
                else{
                    checkoo>>a;
                    checkoo>>a;
                }
            }
            checkoo.close();
            return false;
        }
        bool checkthepass(){
            ifstream checkoo;
            checkoo.open("database of user name and pass.txt",ios::binary);
            string a,b;
            checkoo>>a;
            checkoo>>b;
            while(!checkoo.eof()){
                if(a==user&&b==pass){
                    checkoo.close();
                    return true;
                }
                else{
                    checkoo>>a;
                    checkoo>>b;
                }
            }
            checkoo.close();
            return false;           
        }
};
class signup{
    string user,pass;
    public:
        signup(){}
        signup(string user,string pass):user(user),pass(pass){}
        void setuser(string s){
            user=s;
        }
        void setpass(string p){
            pass=p;
        }
        string getuser()const{
            return user;
        }
        string getpass()const{
            return pass;
        }
        bool check(){
            loop:
            ifstream checkoo;
            checkoo.open("database of user name and pass.txt",ios::binary);
            string a;
            checkoo>>a;
            bool flag=false;
            while(!checkoo.eof()){
                if(a==user){
                    return false;
                }
                else{
                    checkoo>>a;
                    checkoo>>a;
                }
            }
            checkoo.close();
            ofstream input;
            input.open("database of user name and pass.txt",ios::app);
            input<<user<<"\n"<<pass<<"\n";
            return true;
        }
};
class ask{
    string sender,recipient,message,user;
    public:
        ask(){}
        ask(string user):user(user){}
        ask(string sender,string recipient):sender(sender),recipient(recipient){}
        void setsender(string s){
            sender=s;
        }
        void setrecipient(string s){
            recipient=s;
        }
        string getsender()const{
            return sender;
        }
        string getrecipient()const{
            return recipient;
        } 
        void setmessage(string s){
            message=s;
        }
        string getmessage()const{
            return message;
        }
        void setuser(string u){
            user=u;
        }   
        string getuser()const{
            return user;
        }
        bool check(){
            ifstream checkoo;
            checkoo.open("database of user name and pass.txt",ios::binary);
            string data;
            checkoo>>data;
            while(!checkoo.eof()){
                if(recipient==data){
                    checkoo.close();
                    return true;
                }
                checkoo>>data;
                checkoo>>data;
            }
            checkoo.close();
            return false;
        }
        void send(){
            string location=recipient+"_recieve.txt";
            ofstream recievoo,neew;
            neew.open("new.txt",ios::app);
            ifstream codee("code.txt");
            string x;
            codee>>x;
            long long y=stoll(x)+1;
            neew<<y;
            codee.close();
            neew.close();
            remove("code.txt");
            rename("new.txt","code.txt");
            recievoo.open(location,ios::app);
            recievoo<<sender<<"\n"<<x<<"\n"<<message<<"\n1\n";
            ofstream sendoo;
            location = sender+"_send.txt";
            sendoo.open(location,ios::app);
            sendoo<<recipient<<"\n"<<x<<"\n"<<message<<"\n1\n";
            sendoo.close();
            recievoo.close();
        }
        bool ability_to_answer(string ans){
            string location=user+"_recieve.txt";
            ifstream all;
            all.open(location,ios::binary);
            int cnt=1;
            while(!all.eof()){
                string s;
                for(int i=0;i<4;i++){
                    getline(all,s);
                }
                if(s=="1\r"){
                    if(ans==to_string(cnt)){
                        all.close();
                        return true;
                    }
                }
                else{
                    getline(all,s);
                }
                cnt++;
            }
            all.close();
            return false;
        }
        void answer(string choise,string masgoo){
            string location=user+"_recieve.txt",fin,code,temp;
            ifstream all;
            all.open(location,ios::binary);
            ofstream ansoo;
            ansoo.open("new.txt",ios::app);
            int cnt=1;
            while(!all.eof()){
                string s,t;
                getline(all,s);
                if(s.back()==13) s.pop_back();
                else break;
                t=s;
                ansoo<<s<<"\n";
                getline(all,s);
                s.pop_back();
                ansoo<<s<<"\n";
                temp=s;
                getline(all,s);
                s.pop_back();
                ansoo<<s<<"\n";
                getline(all,s);
                if(s=="2\r"){
                    ansoo<<"2\n";
                    getline(all,s);
                    s.pop_back();
                    ansoo<<s<<"\n";
                }
                else{
                    if(choise==to_string(cnt)){
                        ansoo<<"2\n";
                        ansoo<<masgoo<<"\n";
                        fin=t;
                        code=temp;
                    }
                    else{
                        ansoo<<"1\n";
                    }
                }
                cnt++;
            }
            all.close();
            ansoo.close();
            std::filesystem::remove(location);
            std::filesystem::rename("new.txt",location);
            location=fin+"_send.txt";
            all.open(location,ios::binary);
            ansoo.open("new.txt",ios::app);
            while(!all.eof()){
                string s;bool flag=false;
                getline(all,s);
                if(s.back()==13)s.pop_back();
                else break;
                ansoo<<s<<"\n";
                getline(all,s);
                s.pop_back();
                if(s==code){
                    flag=true;
                }
                ansoo<<s<<"\n";
                getline(all,s);
                s.pop_back();
                ansoo<<s<<"\n";
                getline(all,s);
                s.pop_back();
                if(flag){
                    ansoo<<"2\n";
                    ansoo<<masgoo<<"\n";
                }
                else{
                    if(s=="1"){
                        ansoo<<"1\n";
                    }
                    else{
                        getline(all,s);
                        s.pop_back();
                        ansoo<<"2\n";
                        ansoo<<s<<"\n";
                    }
                }
            }
            all.close();
            ansoo.close();
            std::filesystem::remove(location);
            std::filesystem::rename("new.txt",location);                 
        }
        bool printrecieve(){
            int cnt=1;
            string location=user+"_recieve.txt";
            ifstream all;
            all.open(location,ios::binary);
            string msg,fin;
            while(!all.eof()){
                getline(all,msg);
                if(msg.back()==13)
                    msg.pop_back();
                else break;
                cout<<cnt<<" -> from "<<msg<<" : ";
                getline(all,msg);
                getline(all,msg);
                msg.pop_back();
                cout<<msg<<"\n";
                getline(all,msg);
                if(msg=="1\r"){
                    cout<<"enter "<<cnt<<" to answer this question\n\n";
                }
                else{
                    getline(all,msg);
                    msg.pop_back();
                    cout<<"your answer is : "<<msg<<"\n\n";
                }
                cnt++;
            }
            all.close();
            if(cnt==1){
                return false;
            }
            else{
                return true;
            }
        }
        bool printsend(){
            int cnt=1;
            string location=user+"_send.txt";
            ifstream all;
            all.open(location,ios::binary);
            string msg,fin;
            while(!all.eof()){
                getline(all,msg);
                if(msg.back()==13)
                    msg.pop_back();
                else break;
                cout<<cnt<<" -> To "<<msg<<" : ";
                string t=msg;
                getline(all,msg);
                getline(all,msg);
                msg.pop_back();
                cout<<msg<<"\n";
                getline(all,msg);
                if(msg=="1\r"){
                    cout<<t<<" did not answer this question yet\n\n";
                }
                else{
                    getline(all,msg);
                    msg.pop_back();
                    cout<<t<<" answer is : "<<msg<<"\n\n";
                }
                cnt++;
            }
            all.close();   
            if(cnt==1){
                return false;
            }
            else{
                return true;
            }         
        }
        bool ability_to_delete(string choise){
            ifstream filee;
            string location=user+"_send.txt";
            int cnt=1;
            filee.open(location,ios::binary);
            while(!filee.eof()){
                string s,det;
                for(int i=0;i<4;i++){
                    getline(filee,s);
                    if(s.back()!=13){
                        break;
                    }
                    else{
                        if(!i){
                            s.pop_back();
                            det=s;
                        }
                    }
                }
                if(s=="2\r"){
                    getline(filee,s);
                }
                if(choise==to_string(cnt++)){
                    filee.close();
                    setrecipient(det);
                    return true;
                }
            }
            filee.close();
            return false;
        }
        void deletee(string choise){
            ifstream filee,rece;
            ofstream newsend,newrece;
            newsend.open("new.txt",ios::app);
            string location=user+"_send.txt",code;
            int cnt=1;
            filee.open(location,ios::binary);
            while(!filee.eof()){
                string s;
                getline(filee,s);
                if(s.back()!=13){
                    break;
                }
                if(choise==to_string(cnt++)){
                    getline(filee,s);
                    s.pop_back();
                    code=s;
                    getline(filee,s);
                    getline(filee,s);
                    if(s=="2\r")
                        getline(filee,s);
                }
                else{
                    s.pop_back();
                    newsend<<s<<"\n";
                    for(int i=0;i<3;i++){
                        getline(filee,s);
                        s.pop_back();
                        newsend<<s<<"\n";
                    }
                    if(s=="2"){
                        getline(filee,s);
                        s.pop_back();
                        newsend<<s<<"\n";
                    }
                }
            }
            filee.close();
            newsend.close();
            std::filesystem::remove(location);
            std::filesystem::rename("new.txt",location);
            location=getrecipient()+"_recieve.txt";
            rece.open(location,ios::binary);
            newrece.open("new.txt",ios::app);
            while(!rece.eof()){
                string s,t;
                getline(rece,s);
                if(s.back()!=13){
                    break;
                }
                getline(rece,t);
                t.pop_back();
                if(code==t){
                    getline(rece,t);
                    getline(rece,t);
                    if(t=="2\r"){
                        getline(rece,t);
                    }
                }
                else{
                    s.pop_back();
                    newrece<<s<<"\n";
                    newrece<<t<<"\n";
                    for(int i=0;i<2;i++){
                        getline(rece,t);
                        t.pop_back();
                        newrece<<t<<"\n";
                    }
                    if(t=="2"){
                        getline(rece,t);
                        t.pop_back();
                        newrece<<t<<"\n";
                    }
                }
            }
            rece.close();
            newrece.close();
            std::filesystem::remove(location);
            std::filesystem::rename("new.txt",location);          
        }
};
#endif
