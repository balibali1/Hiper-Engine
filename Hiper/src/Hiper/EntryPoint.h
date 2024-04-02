#pragma once

#ifdef HP_PLATFORM_WINDOWS

extern Hiper::Application* Hiper::CreateApplication();

int main(int argc, char** argv)
{
	Hiper::Log::Init();
	HP_CORE_WARN("Initialized Log!");
	int a = 5;
	HP_INFO("Hello! Value = {0}", a);

	auto app = Hiper::CreateApplication();
	app->Run();
	delete app;
}

#endif // HP_PLATFORM_WINDOWS