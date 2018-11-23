#include "MyTestModulePrivatePCH.h"
#include "TaskGraphInterfaces.h"
#include "Stats/Stats.h"

/**
 * GraphTask ≤‚ ‘demo
 */

class FShowcaseTask
{
public:
	FShowcaseTask(int16 _Index) :Index(_Index) {}

	static const TCHAR* GetTaskName()
	{
		return TEXT("FShowcaseTask");
	}

	FORCEINLINE static TStatId GetStatId() {
		RETURN_QUICK_DECLARE_CYCLE_STAT(FShowcaseTask, STATGROUP_TaskGraphTasks);
	}
	static ENamedThreads::Type GetDesiredThread() {
		return ENamedThreads::AnyThread;
	}

	static ESubsequentsMode::Type GetSubsequentsMode() {
		return ESubsequentsMode::TrackSubsequents;
	}

	void DoTask(ENamedThreads::Type CurrentThread, const FGraphEventRef& MyCompletionGraphEvent) {
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:1"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:2"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
		UE_LOG(TestLog, Log, TEXT("Thread %d Run:3"), Index);
		FWindowsPlatformProcess::Sleep(10.0f);
	}

private:
	int16 Index;
};

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyTestTaskGraph, "MyTest.PublicTest.TaskGraphTest",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

	bool FMyTestTaskGraph::RunTest(const FString& Parameters) {

	TGraphTask<FShowcaseTask>::CreateTask(NULL, ENamedThreads::GameThread).ConstructAndDispatchWhenReady(0);
	TGraphTask<FShowcaseTask>::CreateTask(NULL, ENamedThreads::GameThread).ConstructAndDispatchWhenReady(1);
	TGraphTask<FShowcaseTask>::CreateTask(NULL, ENamedThreads::GameThread).ConstructAndDispatchWhenReady(2);

	return true;
}

