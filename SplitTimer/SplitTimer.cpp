#include "SplitTimer.h"
#include <fstream>

namespace SplitTimer
{
	const splitFunc_t defaultSplitPrint = [](std::string label, float diff)
	{
		std::cout << label << ": " << diff << "ms" << std::endl; 
	};
	const splitFunc_t defaultSplitLogToFile = [](std::string label, float diff) {
		std::ofstream logFile("SplitTimer_Log.txt", std::ios::app);

		if (logFile)
			logFile << label << ": " << diff << "ms" << std::endl;
		else
			std::cerr << "Unabled to open timer log for writing" << std::endl;

		logFile.close();
	};

	Timer::Timer()
	{
		splitTime = std::chrono::high_resolution_clock::now();
		startTime = splitTime;
		enableOutput = true;
	}

	void Timer::reset()
	{
		splitTime = std::chrono::high_resolution_clock::now();
		startTime = splitTime;
	}

	void Timer::setOutputEnabled(bool enabled)
	{
		enableOutput = enabled;
	}

	float Timer::split()
	{
		return std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - splitTime).count();
	}

	float Timer::split(std::string label, splitFunc_t printFn)
	{
		float timeDiff = split();
		if (printFn && enableOutput) printFn(label, timeDiff);
		splitTime = std::chrono::high_resolution_clock::now();
		return timeDiff;
	}

	float Timer::elapsedTime()
	{
		return std::chrono::duration<float, std::milli>(std::chrono::high_resolution_clock::now() - startTime).count();
	}

	float Timer::elapsedTime(std::string label, splitFunc_t printFn)
	{
		float timeDiff = elapsedTime();
		if (printFn && enableOutput) printFn(label, timeDiff);
		return timeDiff;
	}
}