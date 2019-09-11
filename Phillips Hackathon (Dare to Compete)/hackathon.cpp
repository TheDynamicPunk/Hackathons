#include <string.h>
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

char strA[2001], strB[2001];
int sizeA = 0, sizeB = 0, aNumOf1 = 0, aNumOf0 = 0, bNumOf1 = 0, bNumOf0 = 0, counter = 0;

void shiftLeft()
{
	int first = strA[0];

	for(int i=0; i<sizeA-1; i++)
	{
		strA[i] = strA[i+1];
	}

	counter++;

	strA[sizeA-1] = first;
}

void shiftRight()
{
	int last = strA[sizeA-1];

	for(int i = sizeA-1; i > 0; i--)
	{
		strA[i] = strA[i-1];
	}

	counter++;

	strA[0] = last;
}

void flipNum()
{
	for(int i = 0; i<sizeB; i++)
	{
		if(strB[i] == '1')
		{
			strA[i] = 1 - int(strA[i]);
			counter ++;
		}
	}
}


int main()
{
    cout<<"Enter binary string a: ";
    cin>>strA;
    cout<<"Enter binary string b: ";
    cin>>strB;

    cout<<"A: "<<strA;
    cout<<"\nB: "<<strB;

	for(int i=0; i<2000; i++)
    {
        if(strA[i] == '0')
        {
        	aNumOf0++;
            sizeA++;
            continue;
        }
        else if ( strA[i] == '1')
        {
        	aNumOf1++;
            sizeA++;
            continue;
        }
        else
        {
            break;
        }
    }

    for(int i=0; i<2000; i++)
    {
        if(strB[i] == '0')
        {
        	bNumOf0++;
            sizeB++;
            continue;
        }
        else if ( strB[i] == '1')
        {
        	bNumOf1++;
            sizeB++;
            continue;
        }
        else
        {
            break;
        }
    }

    if(sizeA == sizeB)
    {
    	while(strcmpi(strA,strB))
    	{
    		flipNum();
    		if(strA == strB)
			{
				break;
			}
			else
			{
				shiftRight();


				if(strcmpi(strA,strB))
				{
					break;
				}
				else
				{
					shiftLeft();
				}
			}
    	}
    }


    cout<<"Size of A is: "<<sizeA;
    cout<<"\nSize of B is: "<<sizeB;
    cout<<"\nOutput: "<<counter;
    return 0;
}
