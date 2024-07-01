#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

const char *opcodes[] = {"mov", "cmp", "add", "sub", "lea", "clr", "not", "inc", "dec", "jmp", "bne", "red", "prn", "jsr", "rts", "stop"};

int findOpCodeIdx(const char *str) 
{
    int num_opcodes = sizeof(opcodes) / sizeof(opcodes[0]);
    for (int i = 0; i < num_opcodes; ++i) 
	{
        if (strcmp(str, opcodes[i]) == 0) 
		{
            return i;
        }
    }
    return -1;
}

int findAddressingMethod(char *operand)
{	
	char *externalWord;

	/* todo: find method 1*/
	if(operand[0] == '#')
	{	
		return 0;
	} else if(operand[0] == '*')
	{
		return 2;
	} else if(operand[0] == 'r' && ((operand[1] - '0') >= 1 && (operand[1] - '0') <= 7)) /* in case there is register included in the string, register is between 0-7 start with an 'r' */ 
	{	
		
		return 3;
	} else {
		return -1;
	}
}

int main() {
    char str[MAX_STRING_LENGTH];
    char *commandName;
	const int firstWordAreField = 2;
	int firstOperandMethod = -1;
	int secondOperandMethod = -1;
	

	char *firstExternalWord;
	char *secondExternalWord;

    printf("Enter a command: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; /* Remove the trailing newline if present */

    commandName = strtok(str, " ");
    if (commandName == NULL) {
        printf("Invalid command.\n");
        return 1;
    }

    int opcodeIdx = findOpCodeIdx(commandName);
    if (opcodeIdx == -1) {
        printf("Invalid opcode: %s\n", commandName);
        return 1;
    }

    printf("Command entered: %s\n", commandName);

    
        char *operandStr;
        char *firstOperand;
        

        operandStr = strtok(NULL, ",");
        if (operandStr != NULL) {
            firstOperand = operandStr;
            printf("First operand: %s\n", firstOperand);
					  
            firstOperandMethod = findAddressingMethod(firstOperand);
            printf("First operand addressing method: %d\n", firstOperandMethod);

        }
	

		if (opcodeIdx >= 0 && opcodeIdx <= 4) {
		char *secondOperand;
				

        operandStr = strtok(NULL, ",");
        if (operandStr != NULL) {
            secondOperand = operandStr;
            printf("Second operand: %s\n", secondOperand);

			       
            secondOperandMethod = findAddressingMethod(secondOperand);
            printf("Second operand addressing method: %d\n", secondOperandMethod);
        }
				

			
			if((firstOperandMethod == 2 || firstOperandMethod == 3) && (secondOperandMethod == 2 || secondOperandMethod == 3))
			{	
				int combined = firstOperandMethod * 10 + secondOperandMethod;
				firstExternalWord = getExternalWord(combined);

			} else {

				if(firstOperandMethod != -1)
				{
				firstExternalWord = getExternalWord(firstOperandMethod);
				}

				if(firstOperandMethod != -1)
				{
				secondExternalWord = getExternalWord(secondOperandMethod);
				}				

			}
			
			




   		}

    return 0;
}
