// a non oop calculator

#include <iostream>                 
#include <cstdlib>                  
#include <cctype>                   
using namespace std;

void eatspaces(char* str);          
double expr(char* str);             
double term(char* str, int& index);   
double number(char* str, int& index); 

const int MAX = 80;         

int main(void)
{
	char buffer[MAX] = { 0 }; 

	cout << endl
		<< "Welcome to the Simple Calculator."
		<< endl
		<< "Enter an expression, or an empty line to quit."
		<< endl;

	for (;;)
	{
		cin.getline(buffer, sizeof buffer);   
		eatspaces(buffer);                    

		if (!buffer[0])                      
			return 0;

		cout << "\t= " << expr(buffer)      
			<< endl << endl;
	}
}


//  blanks
void eatspaces(char* str)
{
	int i = 0;         
	int j = 0;         

	while ((*(str + i) = *(str + j++)) != '\0')   
											
		if (*(str + i) != ' ')                  
			i++;                               
	return;
}


// evaluate 
double expr(char* str)
{
	double value = 0;          
	int index = 0;             

	value = term(str, index);  

	for (;;)                    
	{
		switch (*(str + index++))  
		{
		case '\0':                 
			return value;           

		case '+':                        
			value += term(str, index);    
			break;

		case '-':                         
			value -= term(str, index);     
			break;

		default:                      
			cout << endl               
				<< "Error"
				<< endl;
			exit(1);
		}
	}
}


// value
double term(char* str, int& index)
{
	double value = 0;              

	value = number(str, index);    

	
	while ((*(str + index) == '*') || (*(str + index) == '/'))
	{

		if (*(str + index) == '*')                  
			value *= number(str, ++index);      

		if (*(str + index) == '/')                  
			value /= number(str, ++index);      
	}
	return value;            
}


// number string
double number(char* str, int& index)
{
	double value = 0.0;              

	while (isdigit(*(str + index)))     
		value = 10 * value + (*(str + index++) - 48);

	
	if (*(str + index) != '.')             
		return value;                  

	double factor = 1.0;              
	while (isdigit(*(str + (++index))))  
	{
		factor *= 0.1;                 
		value = value + (*(str + index) - 48)*factor;   
	}

	return value;                    
}
