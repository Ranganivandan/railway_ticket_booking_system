railway ticket booking system


createaccount(): This function allows users to create a new account. It prompts the user to enter a username, email, password, and age. It then writes this information to a file called "accountuserinfo.txt".
login(): This function handles user login. It prompts the user to enter their username and password. It then reads the "accountuserinfo.txt" file to verify the login credentials. It allows a maximum of 3 login attempts before locking the user out.
bookticket(): This function allows users to book train tickets. It prompts the user to enter departure and destination stations, selects a train based on the user's choice, and asks for the number of tickets and class preference. It calculates the total cost, asks for payment confirmation, and then writes the ticket details to the "ticket.txt" file.
ticketdetail(): This function is called from the bookticket() function to handle the details of booking tickets for different trains. It asks for the number of tickets and class preference, calculates the total cost, verifies payment details, and writes the ticket details to the "ticket.txt" file.
cancelticket(): This function allows users to cancel their booked tickets. It checks if the "ticket.txt" file exists, and if so, it clears the contents of the file, effectively canceling the ticket.
Overall, your code seems to be working fine. You might want to handle input validation in certain places to improve robustness. Additionally, using functions to break down the functionality into smaller, more manageable parts is a good practice. Keep up the good work!
