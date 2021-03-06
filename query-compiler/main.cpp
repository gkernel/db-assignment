
#include <stdio.h>
#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "include/parse_tree.h"
#include "include/input_parsetree.h"

extern Operator *expr_root;

extern int open_braces;
extern void indent();

//GLOBAL FILE* used for output file.
FILE *qcode_fp;

void generate_query_code() {

	qcode_fp = fopen("gen_query_code.cpp", "w");

	fprintf(qcode_fp, "#include <stdio.h>\n");
	fprintf(qcode_fp, "#include <ctime>\n");
	fprintf(qcode_fp, "#include <sys/time.h>\n");
	fprintf(qcode_fp, "#include <iostream>\n");
	fprintf(qcode_fp, "#include <string.h>\n");
	fprintf(qcode_fp, "#include <stdint.h>\n");
	fprintf(qcode_fp, "#include <stdlib.h>\n\n");

	fprintf(qcode_fp, "#include <omp.h>\n");
	//fprintf(qcode_fp, "#include <task_scheduler_init.h>\n");
	//fprintf(qcode_fp, "#include <blocked_range.h>\n");
	//fprintf(qcode_fp, "#include <parallel_for.h>\n");
	//fprintf(qcode_fp, "#include <concurrent_hash_map.h>\n\n");
	fprintf(qcode_fp, "#include \"include/hash_map.h\"\n");

	fprintf(qcode_fp, "#include <utility>\n");
	fprintf(qcode_fp, "#include <unordered_map>\n");
	fprintf(qcode_fp, "#include <vector>\n\n");
	fprintf(qcode_fp, "#include \"include/schema.h\"\n");
	fprintf(qcode_fp, "#include \"include/storage.h\"\n\n");
/*
	fprintf(qcode_fp, "using namespace tbb;\n\n");
	fprintf(qcode_fp, "");
	fprintf(qcode_fp, "// Structure that defines hashing and comparison operations for user's type.\n");
	fprintf(qcode_fp, "struct MyHashCompare {\n");
	fprintf(qcode_fp, "    static uint64_t hash( const uint64_t x ) {\n");
	fprintf(qcode_fp, "        uint64_t h = 5892;\n");
	fprintf(qcode_fp, "        h = ((h<<5) + h) * x;\n");
	fprintf(qcode_fp, "        return h;\n");
	fprintf(qcode_fp, "    }\n");
	fprintf(qcode_fp, "//! True if strings are equal\n");
	fprintf(qcode_fp, "    static bool equal( const uint64_t x, const uint64_t y ) {\n");
	fprintf(qcode_fp, "        return x==y;\n");
	fprintf(qcode_fp, "    }\n");
	fprintf(qcode_fp, "};\n");

// A concurrent hash table that maps strings to ints.
	fprintf(qcode_fp, "typedef concurrent_hash_map<uint64_t,uint64_t,MyHashCompare> HashTable;\n");
	fprintf(qcode_fp, "");
*/

	fprintf(qcode_fp, "typedef MyHashMap HashTable;\n");
	fprintf(qcode_fp, "\n");


	fprintf(qcode_fp, "class mystring {\n");
	fprintf(qcode_fp, "public:\n");
	fprintf(qcode_fp, "\tchar str[50];\n\n");

	fprintf(qcode_fp, "\tmystring operator=(char *_str);\n");
	fprintf(qcode_fp, "\tmystring operator=(uint64_t val);\n");
	fprintf(qcode_fp, "\tint operator==(uint64_t val);\n");
	fprintf(qcode_fp, "\tint operator==(const char* _str);\n");
	fprintf(qcode_fp, "\tint operator==(mystring _mystr);\n");
	fprintf(qcode_fp, "};\n\n");
	fprintf(qcode_fp, "mystring mystring::operator=(char *_str) {\n");
	//fprintf(qcode_fp, "\tstr = (char*)malloc(sizeof(char)*strlen(_str));\n");
	fprintf(qcode_fp, "\tstrcpy(str, _str);\n");
	fprintf(qcode_fp, "\treturn *this;\n");
	fprintf(qcode_fp, "}\n\n");
	fprintf(qcode_fp, "mystring mystring::operator=(uint64_t val) {\n");
	//fprintf(qcode_fp, "\tstr = (char*)malloc(sizeof(char)*20);\n");
	fprintf(qcode_fp, "\tsprintf(str, \"%%llu\", val);\n");
	fprintf(qcode_fp, "\treturn *this;\n");
	fprintf(qcode_fp, "}\n\n");
	fprintf(qcode_fp, "int mystring::operator==(uint64_t val) {\n");
	fprintf(qcode_fp, "\tchar temp_str[20];\n");
	fprintf(qcode_fp, "\tsprintf(temp_str, \"%%llu\", val);\n");
	fprintf(qcode_fp, "\treturn !strcmp(str, temp_str);\n");
	fprintf(qcode_fp, "}\n\n");	
	fprintf(qcode_fp, "int mystring::operator==(const char* _str) {\n");
	fprintf(qcode_fp, "\treturn !strcmp(str, _str);\n");
	fprintf(qcode_fp, "}\n\n");
	fprintf(qcode_fp, "int mystring::operator==(mystring _mystr) {\n");
	fprintf(qcode_fp, "\treturn !strcmp(str, _mystr.str);\n");
	fprintf(qcode_fp, "}\n\n");		
	fprintf(qcode_fp, "");
	fprintf(qcode_fp, "");

	indent();
	fprintf(qcode_fp, "void query2() {\n");

	open_braces++;
/*	indent();
	fprintf(qcode_fp, "task_scheduler_init init;\n");*/
	indent();
	fprintf(qcode_fp, "timeval start_time, end_time, time_taken;\n\n");
	indent();
	fprintf(qcode_fp, "gettimeofday(&start_time,NULL);\n\n");

	expr_root->produce();

	indent();
	fprintf(qcode_fp, "gettimeofday(&end_time,NULL);\n\n");
	indent();
	fprintf(qcode_fp, "time_taken.tv_sec = end_time.tv_sec - start_time.tv_sec;\n");
	indent();
	fprintf(qcode_fp, "time_taken.tv_usec = end_time.tv_usec - start_time.tv_usec;\n\n");
	indent();
	fprintf(qcode_fp, "cout << \"Time Taken \" << time_taken.tv_sec << \" s \" << time_taken.tv_usec << \" us\\n\";\n");


	open_braces--;
	indent();
	fprintf(qcode_fp, "}\n");

	fclose(qcode_fp);
}


int main() {

	generate_parse_tree();

	generate_query_code();

	return 0;
}