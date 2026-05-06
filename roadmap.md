# Project GPU Vanguard: Execution Plan

To build a native Linux GPU Profiler and Telemetry Daemon tailored for "Linux"😅.

### The C++ Rules to Follow

Use modern C++14 and C++17. 

*   `std::make_unique`: use this as default way to create objects to prevent memory leaks.
*   **Generic Lambdas**: use `auto` parameters in lambdas to iterate over directories cleanly.
*   `std::shared_timed_mutex`: use this so multiple threads can read my telemetry data at the same time without blocking, while keeping it locked when the engine writes new data.
*   `std::filesystem`: use this to navigate the Linux directory structure instead of older C style calls.
*   `std::string_view`: use this to parse text from Linux system files without copying strings or allocating new memory.
*   `std::optional`: return this instead of null values when a file is missing or locked, forcing me to handle missing data safely.

### Week 1: Linux File I/O and Parsing Engine

Show I can pull raw data out of the Linux kernel efficiently.

*   **Day 1 to 2**: explore `/sys/class/drm/` in my Fedora terminal to find the specific files holding my GPU clock speed, memory usage, and temperature. write down the exact paths.
*   **Day 3 to 4**: create a `SysfsReader` class. write a `read_sysfs_value` function that uses `<fstream>` to open the file and returns a `std::optional<std::string>`.
*   **Day 5 to 6**: write the parsing logic. The kernel outputs text like "temp1_input: 45000". use `std::string_view` and `std::from_chars` to extract that number and convert it to an integer without allocating new strings.
*   **Day 7**: test the program to make sure it prints the correct GPU temperature to my console.

### Week 2: Structuring the Telemetry Core

build a robust data structure to hold the state of the GPU using RAII principles.

*   **Day 1 to 2**: create a `GpuTelemetry` struct containing basic data types like `int temperature`, `unsigned long memory_used`, and `int core_clock`.
*   **Day 3 to 5**: build the `VanguardEngine` class to own the `SysfsReader`. instantiate it using `std::make_unique<VanguardEngine>()`. write an update method inside the engine that calls the reader and populates my struct.
*   **Day 6 to 7**: use C++17 structured bindings to unpack the data in `main.cpp` using syntax like `auto [temp, mem, clock] = engine->get_latest_telemetry();` and print the results to the terminal.

### Week 3: Threading and Concurrency

A profiler needs to run continuously in the background, so need to implement multitasking.

*   **Day 1 to 3**: move my update method into an infinite while loop running on a separate `std::thread`. add a 500ms sleep timer to poll the kernel twice a second.
*   **Day 4 to 5**: protect my data from race conditions. wrap my `GpuTelemetry` struct in a `std::shared_timed_mutex`.
*   **Day 6 to 7**: implement a clean shutdown. use a `std::atomic<bool>` flag. When I hit Ctrl+C, the program will toggle the flag and safely terminate the background thread.

### Week 4: The Terminal UI

Make it a professional tool similar to htop.

*   **Day 1 to 2**: link the `ncurses` library to my C++ project and create a `DisplayManager` class.
*   **Day 3 to 5**: map out the terminal layout. draw static borders and labels for GPU Temp, VRAM Usage, and Core Clock.
*   **Day 6 to 7**: connect the UI to the engine. My main thread will continuously read from the `VanguardEngine` and push those numbers to specific `ncurses` coordinates so I can see the data update live.

### Week 5: The WebGPU Lab Rats

write small scripts to force the GPU to work hard so I can see Vanguard catch the hardware spikes.

*   **Day 1 to 3**: write a minimal WebGPU script that allocates massive `GPUBuffer` objects. run it and watch my Vanguard VRAM metric skyrocket.
*   **Day 4 to 6**: write a WebGPU compute shader that executes a heavy infinite loop of matrix multiplications. run it and watch Vanguard track the rising temperature and drops in clock speed.
*   **Day 7**: test under load and fix any race conditions or file read errors if Vanguard crashes.

### Week 6: System Integration and Polish

Make Vanguard a native, low overhead Linux application.

*   **Day 1 to 3**: profile my code using Valgrind or manual review. Make sure absolutely zero `new`, `malloc`, or `std::string` allocations happen during the update loop. Everything must be pre-allocated during startup.
*   **Day 4 to 6**: write a `.service` file for `systemd` to run Vanguard silently in the background as a daemon. have it log metrics to a CSV file to understand Linux system deployment.
*   **Day 7**: have a project deployment and yeah publish stuff to the net :D