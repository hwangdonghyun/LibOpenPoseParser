#include <stdio.h>
#include <Windows.h>
#include "SimpleFileOperation.h"

#include <iostream>

#include <json/json.h>

#define JSONDATADIR "C:\\Users\\Hwang Dong Hyun\\Documents\\TestResult\\res\\"


int main(void)
{
	std::string jsonDirectory = JSONDATADIR;
	std::string fileName;
	std::string front = "TennisShort_";
	std::string middle;
	std::string rear = "_pose.json";
	char numbers[13];
	Json::Value root;
	Json::Reader reader;

	for (int i = 1; i < 100; i++)
	{
		sprintf(numbers, "%012d", i);
		middle = numbers;
		fileName = front + middle + rear;
		fileName = jsonDirectory + fileName;
		char* data = openAndReadFile((char*)fileName.c_str());
		std::string str = data;
		if (!reader.parse(str, root))
		{
			printf("Parsing is fail\n");
			exit(-1);
		}
		Json::Value people = root["people"];

		for (int i = 0; i < people.size(); i++)
		{
			Json::Value bp = people[i]["body_parts"];
			for (int j = 0; j < bp.size(); j++)
			{
				std::cout << bp[j].asDouble() << std::endl;
			}

		}
		
		//printf("%s", data);
		safeFree(data);
	}
}

/*
bool ReadFromFile(const char* filename, char* buffer, int len)
{
	FILE* r = fopen(filename, "rb");
	if (NULL == r)
		return false;
	size_t fileSize = fread(buffer, 1, len, r);
	fclose(r);
	return true;
}
int main()
{
	const int BufferLength = 1024;
	char readBuffer[BufferLength] = { 0, };
	if (false == ReadFromFile("C:\\Users\\Hwang Dong Hyun\\Documents\\TestResult\\res\\TennisShort_000000000000_pose.json", readBuffer, BufferLength))
		return 0;
	std::string config_doc = readBuffer;
	Json::Value root;
	Json::Reader reader;
	bool parsingSuccessful = reader.parse(config_doc, root);
	if (!parsingSuccessful)
	{
		std::cout << "Failed to parse configuration\n"
			<< reader.getFormatedErrorMessages();
		return 0;
	}
	Json::Value test = root["people"];
	
	for (int i = 0; i < test.size(); i++)
	{
		Json::Value bp = test[i]["body_parts"];
		for (int j = 0; j < bp.size(); j++)
		{
			std::cout << bp[j].asDouble() << std::endl;
		}

	}
	return 0;
}
*/