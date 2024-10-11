# Ask.fm Simulation

## Overview
The Ask.fm Simulation project is designed to replicate the core functionalities of the Ask.fm platform, allowing users to ask and answer questions anonymously. Built in C++, the application utilizes files as a simple database to store user credentials, messages, and their statuses. This implementation demonstrates the effective use of file handling for data management, simulating a real-world social interaction platform.

## Features

### User Authentication:
- Users can sign up and log in using their usernames and passwords. Credentials are stored in a text file, ensuring that user data is persistently saved.

### Messaging System:
- Users can send questions to others and receive responses. Each message is recorded in individual text files, categorized by the sender and recipient.

### Answering Questions:
- Users can view received questions and respond to them. The application keeps track of which questions have been answered or remain unanswered.

### Message Management:
- Users can view their sent and received messages, providing transparency in communication. The system allows for the deletion of sent messages, updating the database accordingly.

### Data Storage:
- All user data, including usernames, passwords, and message histories, are stored in text files, simulating a basic database. This approach simplifies data management and ensures data persistence even when the application is closed.

### User-Friendly Interface:
- The command-line interface is straightforward, guiding users through the authentication and messaging processes with clear prompts.
