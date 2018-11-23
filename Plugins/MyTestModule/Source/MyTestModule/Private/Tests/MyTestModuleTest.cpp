#include "MyTestModulePrivatePCH.h"

DEFINE_LOG_CATEGORY_STATIC(TestLog, Log, All);
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMutilThreadTest, "MyTest.PublicTest.MutilThreadTest",
	EAutomationTestFlags::EngineFilter | EAutomationTestFlags::EditorContext)

bool FMutilThreadTest::RunTest(const FString& Parameters)//并行 与并发
{
	UE_LOG(TestLog, Log, TEXT("HELLO"));

	return true;
}