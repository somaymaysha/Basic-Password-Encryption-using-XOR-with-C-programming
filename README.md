This repository includes a basic C application that uses the XOR (exclusive OR) method to show how to encrypt and decode passwords.  The application lets users enter a password, encrypts it using a predetermined encryption key, and then uses the same key to decrypt it back to its original form.  The same key is used for both encryption and decryption in XOR encryption, a simple symmetric encryption method.

Features: 

● Use the XOR operation to both encrypt and decrypt a password;

● The encryption key is fixed and utilized for both encryption and decryption.

● To ensure the operation is successful, the decrypted password is printed after the encrypted password is shown in hexadecimal format.


How It Works.

 1. The user enters a password (at least eight characters long).
 2. The password is encrypted using an XOR operation and a set key.
 3. The encrypted password is shown in hexadecimal format.
 4. To decrypt the password, apply the same XOR technique again.
 5. The decrypted password is printed to ensure it matches the original input.

 The Program Flow
 
 ● Step 1: The user is required to enter a password of at least 8 characters.
 
 ● Step 2: The application encrypts the password using XOR and a preset key.
 
 ● Step 3: The encrypted password appears in hexadecimal format.
 
 ● Step 4, the application decrypts the password using the same key and XOR operation.
 
 ● Step 5: Print the decrypted password to validate successful encryption and decryption.

XOR Encryption and Decryption:

 The XOR bitwise operation is important to the encryption and decryption mechanisms.  XORing a password character with a key character results in an

 Encrypted character.  Applying XOR again with the same key returns the original character.
 
 Example
 Sample  Run: sh.
 
 Copy:
 Enter your password (8 or more characters):  MySecurePass
 
 Password encrypted in hexadecimal: 4D 79 53 65 63 75 72 65 50 61 73.
 
 Decrypted password: MySecurePass.

 Requirements
 
● C compiler (e.g., GCC or Clang)

● A terminal/command line interface
Compilation and Execution

To compile and run the program:

Clone the repository:
sh
Copy the code
git clone
https://github.com/your-username/basic-password-encryption-xor-c.git
cd basic-password-encryption-xor-c

1.
Compile the code:
sh
Copy
gcc -o xor_encryption xor_encryption.c

2.
Run the program:
sh
Copy
./xor_encryption

3.
Code Explanation
xor_encrypt_decrypt function
This function performs the XOR operation on each character of the input (password) with the
corresponding character of the key. The key is used in a repeating manner if the password is
longer than the key.

c
Copy the code
void xor_encrypt_decrypt(char *input, const char *key) 
{
int key_length = strlen(key);
for (int i = 0; i < strlen(input); i++) {
input[i] = input[i] ^ key[i % key_length];
}

Limitations

● XOR encryption is not secure for real-world applications and is used here for
educational purposes only.

● The key is hardcoded, which may not be suitable for practical use cases.

● The program expects the password to be at least 8 characters long


