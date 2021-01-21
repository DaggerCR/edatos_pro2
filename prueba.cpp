#include <iostream>
#include "rapidxml.hpp"
#include <fstream>
#include <vector>
#include <string> 
#include <bits/stdc++.h>
#include "estructuras.h"

using namespace rapidxml;
using namespace std;

xml_document<> doc;
xml_node<> * pathway = NULL;
string file;


vector<Entry> vEntry(99);


int contarEntry(string file)
{
	int n = file.length();
    char Cfile[n + 1];
    strcpy(Cfile, file.c_str());
	
	int j = 0;
		
	ifstream in(Cfile);
  	ofstream out("out.xml");
  	char ch; 
  	bool last_was_space = false ;
  	while(in.get(ch))
  	{
    	if( ch != 32 )
    	{
      		out.put(ch);
    	}
    	else 
			if( !last_was_space )
    		{
       			
    		}
  	}

	
	ifstream fin;
	fin.open("out.xml");
	if(fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
	string search;
	cout << "Please enter a name: ";
	cin  >> search;
	bool isFound=0;	
	
	int k = 0;
	while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
		for(int i=0;i<search.size();i++)
		{
			if(temp[i]==search[i])
				{
					isFound = 1;
					k++;
					if(k>8)
						j++;
				}
			else
			{
				k=0;
				break;
			}
		}
	}
		if(isFound)
		{
			cout << "times: "<< j;			
			//break;
		}	
		fin.close();
		
		return j;
}

void verID(string file)
{
	
	cout << "\n\tProbando el archivo " << file << endl;
	
	int total = contarEntry(file);
	
	int n = file.length();
    char Cfile[n + 1];
    strcpy(Cfile, file.c_str());
	
    ifstream theFile(Cfile);
    	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    	
	if (theFile.is_open()) 
	{
		
		for(int x= 0;x<99;x++)
		{
			Entry *p = new Entry();
			vEntry.push_back(*p);
		}
		
		buffer.push_back('\0');
	    // Parse the buffer
	    doc.parse<0>(&buffer[0]);
	    // Find out the root node
	    pathway = doc.first_node("pathway");
	    // Iterate over the student nodes
	    
		int x = 0;
	
			for(xml_node<> * entry = pathway->first_node("entry"); entry; entry = entry->next_sibling())
	    	{
	    	
	        	cout << "\nID = " << entry->first_attribute("id")->value();
	        	vEntry[x].asignar(entry->first_attribute("id")->value(),
				entry->first_attribute("name")->value(),
				entry->first_attribute("type")->value()); 
				x++;
				if(x == total)
					break;
				
	    	}
	    
	}
	else
	{
		printf("\tArchivo no encontrado\n");
	}
	
	
}


void cargarXML()
{
	printf("\n\n\t\tCargar KGML\n");
	printf("\tDigite el nombre del archivo: ");
	cin >> file;

}

int main(void)
{
	
	
	
		
		
	int opcion = -1;
	
	while(opcion != 6)
	{
		printf("\n\t\tMenu\n");
		printf("\t1. Cargar KGML\n");
		printf("\t2. Ver rutas disponibles\n");	
		printf("\t3. Comparar rutas\n");	
		printf("\t4. Generar gráfico\n");	
		printf("\t5. Modo inspeccionar\n");
		printf("\t6. Salir\n");	
		printf("\tSu opción: ");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				cargarXML();
				break;
			case 2:
				verID(file);
				break;
				
			default:
				printf("\n\tOpción no válida\n\n");
		}	
		
	}
		   	   
   
   
   
    return 0;
	
   
}
