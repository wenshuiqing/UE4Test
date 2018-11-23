#include <functional>
#include <thread>
#include "MyTestModulePrivatePCH.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FSTDThreadTest,"MyTest.PublicTest.STDThreadTest",
	EAutomationTestFlags::EditorContext|EAutomationTestFlags::EngineFilter)

bool FSTDThreadTest::RunTest(const FString& Parameters) 
{
	std::function<void(int16)> TaskFunction=[=](int16 Index) {
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:1"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:2"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:3"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
	
	};

	new std::thread(TaskFunction, 0);
	new std::thread(TaskFunction, 1);
	new std::thread(TaskFunction, 2);

	return true;

}