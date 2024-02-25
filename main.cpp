  /* صلي علي محمد */
  #include<bits/stdc++.h>
  #include"m.h"
  using namespace std;
  signed main(){
    cout<<"========================\n     Welcome To Ask\n========================\n\n";
    string choise;
    transport1:
    cout<<"Enter 1 To Login and 2 To Sign up : ";
    cin>>choise;
    string final_user;
    if(choise=="1"){ // for login
      string s,p;
      cout<<"Enter The User : ";
      cin>>s;
      cout<<"Enter The Pass : ";
      cin>>p;   
      login x(s,p);
      while(!x.checktheuser()){
        cout<<"the user is not correct please enter another or enter 1 to sign up : ";
        string another;
        cin>>another;
        if(another=="1"){
          goto transport;
        }
        x.setuser(another);
      }
      int cnt=10;
      while(!x.checkthepass()){
        cnt--;
        if(!cnt) break;
        cout<<"the pass is incorrect you still have "<<cnt<<" trial : ";
        string another;
        cin>>another;
        x.setpass(another);
      }
      if(!cnt){
        cout<<"all passwords you entered is incorrect ";
        goto transport1;
      }
      final_user=x.getuser();
    }
    else if(choise=="2"){ // for signup
      transport:
      string s,p;
      cout<<"Enter The User : ";
      cin>>s;
      cout<<"Enter The Pass : ";
      cin>>p;
      signup y(s,p);
      while(!y.check()){
        cout<<"this user is not available enter another : ";
        string another;
        cin>>another;
        y.setuser(another);
      }
      cout<<"=====Successfully SignedUp=====\n\n";
      final_user=y.getuser();
    }
    else{
      "not available choise :(\n";
      goto transport1;
    }
    cout<<"Welcome "<<final_user<<" :)\n\n";
    transport5:
    cout<<"1->show all message you got\n\n2->show all message you sent\n\n3->send message\n\n4->answer a message you have got\n\n5->delete a message you have sent\n\n6->to exit\n\n";
    choiseloop:
    string choise2; // for ASK
    cin>>choise2;
    if(choise2=="1"||choise2=="4"){
      ask allmsg(final_user);
      if(allmsg.printrecieve()){
      cout<<"enter the number of the message you want to answer : ";
      repeat:
      string ans;
      cin>>ans;
      if(allmsg.ability_to_answer(ans)){
        cout<<"Enter your answer in one line : ";
        string masgoo;
        cin.ignore();
        getline(cin,masgoo);
        allmsg.answer(ans,masgoo);
        cout<<"=====DONE=====\n";
        goto transport5;
      }
      else{
        cout<<"Not Aailable Choise Enter Another : ";
        goto repeat;
      }
      }
      else{
        cout<<"you dont have got any messages yet :( enter 1 to go to the main menu :";
        string x;
        cin>>x;
        if(x=="1"){
          goto transport5;
        }
      }
    }
    else if(choise2=="2"||choise2=="5"){
      ask allmsg(final_user);
      if(!allmsg.printsend()){
        cout<<"you did not send any question yet enter 1 to back to the main menu : ";
        string x;
        cin>>x;
        if(x=="1"){
          goto transport5;
        }
        else{
          return 0;
        }
      } 
      cout<<"enter 1 to back to the main menu or 2 to delete a question : ";
      string x;
      cin>>x;
      if(x=="1"){
        goto transport5;
      }
      else{
        deletoo:
        cout<<"enter the number of the message you want to delete : ";
        string choise;
        cin>>choise;
        if(allmsg.ability_to_delete(choise)){
          allmsg.deletee(choise);
          cout<<"Delete completed :)\n";
          goto transport5;
        }
        else{
          cout<<"not correct choise\n";
          goto deletoo;
        }
      }
    }
    else if(choise2=="3"){
      transport2:
      cout<<"enter user, the person you want to send to : ";
      string recipient;
      cin>>recipient;
      ask sender(final_user,recipient);
      while(!sender.check()){
        cout<<"this user does not exist enter another : ";
        string another;
        cin>>another;
        sender.setrecipient(another);
      }
      string message;
      cout<<"enter the message in one line : ";
      cin.ignore();
      getline(cin,message);
      sender.setmessage(message);
      sender.send();
      cout<<"the message has been sent :)\n";
      cout<<"if you want to sent another message enter 1 or any thing else to go to the main menu : ";
      string fg;
      cin>>fg;
      if(fg=="1"){
        goto transport2;
      }
      else{
        goto transport5;
      }
    }
    else if(choise2=="6"){
      // ezzayaak :)
    }
    else{
      "the input is invalid enter another : ";
       goto choiseloop;
    }
  }