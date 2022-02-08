#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // DECLARATION
    char user[10] = "";
    char password1[10] = "";
    char password2[10] = "";
    int samePasswordControl;

    char createdUser[10] = "";
    char createdPassword[10] = "";
    int createdUserControl;
    int createdPasswordControl;

    //---------------------------

    char existedUser[10] = "test";
    char existedPassword[10] = "1234";
    int existedUserControl;
    int existedPasswordControl;
    int loop=0;

    // three login attempts
    while(loop<3)
    {
        loop++;
        // ASSIGNMENT (INPUT)
        printf("User: \n");
        scanf("%s", &user);
        existedUserControl=strcmp(user, existedUser);


        if(existedUserControl != 0) // if user doesn't exist yet, create user:
        {
            //---------------------------
            printf("User does not exist, create user '%s'.\n", user);
            printf("Enter a password: \n");
            scanf("%s", &password1);

            printf("Enter a password again: \n");
            scanf("%s", &password2);

            // PROCESSING
            //------------
            samePasswordControl=strcmp(password1, password2);
            if(samePasswordControl==0)
            {
                //printf("%s", "Le password sono uguali.\n");
                printf("%s", "Registered User!\n");
                strcpy(createdUser, user);
                strcpy(createdPassword, password1);

                printf("%s", "Login your created user.\n");
                printf("User: \n");
                scanf("%s", &user);
                printf("Password: \n");
                scanf("%s", &password1);
                createdUserControl=strcmp(user, createdUser);
                createdPasswordControl=strcmp(password1, createdPassword);

                if(createdUserControl == 0 && createdPasswordControl == 0)
                {
                    printf("%s", "Connected!\n");
                    break;
                }
                else
                {
                    printf("%s", "Access denied.\n");
                    break;
                }
            }
            else
            {
                //printf("%s", "Passwords are not the same.\n");
                printf("%s", "Wrong password. User not registered.\n");

            }
        }
        //-----------------
        if(existedUserControl == 0) // if user == userTest, ask for userTest's password
        {
            printf("Password: \n");
            scanf("%s", &password1);
            existedPasswordControl=strcmp(password1, existedPassword);
            if(existedPasswordControl==0)
            {
                printf("%s", "Connected!\n");
                break;
            }
            else
            {
                printf("%s", "Access denied.\n");
            }
        }

    }




    //OUTPUT

    printf("\n");

    system("PAUSE");
    return 0;

}
