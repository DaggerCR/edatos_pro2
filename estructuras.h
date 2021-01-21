#include <fstream>
#include <vector>
#include <string> 
#include <bits/stdc++.h>
#include <iostream>


using namespace std;

struct Entry
{
	char id[99];
	char name[99];
	char type[99];
	char reaction[99];
	
	Entry()
	{
		
	}
	
	Entry(char pid[99], char pname[99], char ptype[99], char preaction[99])
	{
		for(int x = 0;x<99;x++)
		{
			id[x] = pid[x];
		}
		/*
		type = ptype;
		reaction = preaction;
		*/
	}
	
	void asignar(char pid[99], char pname[99], char ptype[99])
	{
		for(int x = 0;x<99;x++)
		{
			id[x] = pid[x];
		}
	}
	
};
