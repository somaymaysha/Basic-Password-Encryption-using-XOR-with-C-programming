#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// XOR encryption/decryption function
void xor_encrypt_decrypt(char *input, const char *key) {
    int key_length = strlen(key);
    for (int i = 0; i < strlen(input); i++) {
        // XOR each character of the input with the corresponding character of the key
        input[i] = input[i] ^ key[i % key_length];
    }
}

int main() {
    char *password;  //  memory for the password
    size_t password_size = 256;  // Maximum length for the password input
    const char *key = "ThisIsAComplexKey!123";  // Fixed key for XOR encryption (contains letters, numbers, and special chars)

    //  allocate memory for the password
    password = (char *)malloc(password_size * sizeof(char));
    if (password == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt for password input (password can be 8 or more characters)
    printf("Enter a password (8 or more characters): ");
    fgets(password, password_size, stdin);
    
    // Remove the newline character if present
    password[strcspn(password, "\n")] = 0;

    // Check if password length is at least 8 characters
    if (strlen(password) < 8) {
        printf("Invalid input! The password must be at least 8 characters.\n");
        free(password);
        return 1;  // Exit program if password is too short
    }

    // Encrypt the password using XOR
    xor_encrypt_decrypt(password, key);
    printf("Encrypted password (in hexadecimal): ");
    for (int i = 0; i < strlen(password); i++) {
        printf("%02X", (unsigned char)password[i]);  // Print encrypted password in hexadecimal
    }
    printf("\n");

    // Decrypt the password (XOR again with the same key)
    xor_encrypt_decrypt(password, key);
    printf("Decrypted password: %s\n", password);

    // Free the allocated memory for password
    free(password);

    return 0;
}
