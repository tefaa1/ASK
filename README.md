# Ask.fm Simulation

## Overview
This project simulates the functionality of the popular social Q&A platform, ask.fm, using C++. It allows users to create accounts, send and receive messages anonymously, and interact with one another through questions and answers. The system is designed to mimic the real-life experience of ask.fm while maintaining a simple and efficient interface.

## Features

### User Registration and Login
- Users can create accounts by signing up with a username and password.
- The login system checks credentials against a file-based database to authenticate users.

### File-Based Database
- User credentials and messages are stored in text files, providing a simple yet effective way to manage data.
- Each user has a dedicated file that keeps track of their sent and received messages, ensuring that the information persists between sessions.

### Send Messages
- Users can send messages to other registered users.
- Messages are stored in the recipient's file, along with metadata such as sender information and message ID, enabling easy retrieval and management.

### View Messages
- Users can view all messages they have received or sent, displaying whether they have been answered or remain unanswered.

### Reply to Messages
- Users have the option to reply to incoming messages, which are then updated in both the sender's and recipient's files, maintaining a complete conversation history.

### Delete Messages
- Users can delete messages they have sent, with the changes reflected in the respective files, ensuring the database stays current and relevant.

## Conclusion
This simulation of ask.fm provides a practical example of handling user interactions in a social media context while showcasing file handling in C++. The project emphasizes data management and user experience, making it a valuable exercise in C++ programming.
