#include <Python.h>
#include <string>
#include <iostream>
#include <fstream>

int main( int argc, char** argv ) {

	if ( argc == 2 ) {

		std::string code;

		std::ifstream file;
		file.open( argv[ 1 ] );

		if ( file.is_open( ) ) {

			code.append( "from sys import path as dontknow\ndontknow.append('python-modules')\n" );

			for ( std::string line; getline( file, line ); ) {
				if ( line == "#!/usr/bin/env unite" || line == "#!/usr/bin/env python3" ) {
					code.insert( 0, line + "\n" );
				} else {
					code.append( line + "\n" );
				}
			}

			file.close( );

		} else {
			std::cout << "Unable to open the file!" << std::endl;
		}

		Py_Initialize( );
		PyRun_SimpleString( code.c_str( ) );
		Py_Finalize( );

	}

	return 0;
}
