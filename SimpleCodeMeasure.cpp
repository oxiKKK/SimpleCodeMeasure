#include <iostream>
#include "CCodeMeasurement.h"
#include <Windows.h>

int main()
{
	CODE_MEASUREMENT_START(CFunctionSleepPrecision);
	Sleep(1000);
	CODE_MEASUREMENT_END(CFunctionSleepPrecision);

	CODE_MEASUREMENT_START(CFunctionSleepPrecision1);
	Sleep(1);
	CODE_MEASUREMENT_END(CFunctionSleepPrecision1);

	std::cout << "---- MEASURING START ----" << '\n';

	for (const auto& m : CodeMeasurements)
		std::cout << m.GetName() << ": took " << m.GetDeltaTime() << " seconds" << '\n';

	std::cout << "---- MEASURING END ----" << '\n';


	std::cin.get();
}

