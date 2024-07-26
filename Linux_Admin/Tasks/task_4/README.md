# Task 4 Linux Admin

Q1) script for user and group

![image](https://github.com/user-attachments/assets/335da585-6903-4e7d-afa2-49c53537e08e)


Q2)
1. Create a supplementary (Secondary) group called pgroup with group ID of 30000
```markdown
sudo groupadd -g 30000 pgroup
```

2. Lock any user-created account so they can't log in
```markdown
sudo usermod -L yourName
```
3. Delete user account
```markdown
sudo userdel yourName
# If you also want to delete the user's home directory and mail spool, use:
# sudo userdel -r yourName
```
4. Delete group account
```markdown
sudo groupdel pgroup
```
5. Difference between adduser and useradd with examples

adduser and useradd are both commands used to create user accounts in Linux, but they have differences in functionality and ease of use:
- useradd is a low-level utility for adding users. It requires manual specification of many options and does not create home directories or set passwords by default.
- adduser is a high-level utility (often a Perl script) that uses useradd in the background but provides a more user-friendly interface. It prompts the user for input and handles many configurations automatically.
  
