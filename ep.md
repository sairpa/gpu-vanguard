# Project GPU Vanguard: Execution Plan

A native Linux GPU Profiler and Telemetry Daemon tailored for "Linux"😅.

### Milestone 1: Linux File I/O and Parsing Engine

Show I can pull raw data out of the Linux kernel efficiently.

- [ ] explore `/sys/class/drm/` in Fedora terminal to find the specific files holding GPU clock speed, memory usage, and temperature. write down the exact paths.
- [ ] create a `SysfsReader` class. write a `read_sysfs_value` function that uses `<fstream>` to open the file and returns a `std::optional<std::string>`.
- [ ] write the parsing logic. The kernel outputs text like "temp1_input: 45000". use `std::string_view` and `std::from_chars` to extract that number and convert it to an integer without allocating new strings.
- [ ] test the program to make sure it prints the correct GPU temperature to console.

### Milestone 2: Structuring the Telemetry Core

build a robust data structure to hold the state of the GPU using RAII principles.

- [ ] create a `GpuTelemetry` struct containing basic data types like `int temperature`, `unsigned long memory_used`, and `int core_clock`.
- [ ] build the `VanguardEngine` class to own the `SysfsReader`. instantiate it using `std::make_unique<VanguardEngine>()`. write an update method inside the engine that calls the reader and populates struct.
- [ ] use C++17 structured bindings to unpack the data in `main.cpp` using syntax like `auto [temp, mem, clock] = engine->get_latest_telemetry();` and print the results to the terminal.

### Milestone 3: Threading and Concurrency

A profiler needs to run continuously in the background, so need to implement multitasking.

- [ ] move update method into an infinite while loop running on a separate `std::thread`. add a 500ms sleep timer to poll the kernel twice a second.
- [ ] protect data from race conditions. wrap `GpuTelemetry` struct in a `std::shared_timed_mutex`.
- [ ] implement a clean shutdown. use a `std::atomic<bool>` flag. When I hit Ctrl+C, the program will toggle the flag and safely terminate the background thread.

### Milestone 4: The Terminal UI

Make it a professional tool similar to htop.

- [ ] link the `ncurses` library to C++ project and create a `DisplayManager` class.
- [ ] map out the terminal layout. draw static borders and labels for GPU Temp, VRAM Usage, and Core Clock.
- [ ] connect the UI to the engine. main thread will continuously read from the `VanguardEngine` and push those numbers to specific `ncurses` coordinates so I can see the data update live.

### Milestone 5: The WebGPU Lab Rats

write small scripts to force the GPU to work hard so I can see Vanguard catch the hardware spikes.

- [ ] write a minimal WebGPU script that allocates massive `GPUBuffer` objects. run it and watch Vanguard VRAM metric skyrocket.
- [ ] write a WebGPU compute shader that executes a heavy infinite loop of matrix multiplications. run it and watch Vanguard track the rising temperature and drops in clock speed.
- [ ] test under load and fix any race conditions or file read errors if Vanguard crashes.

### Milestone 6: System Integration and Polish

Make Vanguard a native, low overhead Linux application.

- [ ] profile code using Valgrind or manual review. Make sure absolutely zero `new`, `malloc`, or `std::string` allocations happen during the update loop. Everything must be pre-allocated during startup.
- [ ] write a `.service` file for `systemd` to run Vanguard silently in the background as a daemon. have it log metrics to a CSV file to understand Linux system deployment.
- [ ] have a project deployment and yeah publish stuff to the net :D

### The C++ Rules to Follow

Use modern C++14 and C++17. 

*   `std::make_unique`: use this as default way to create objects to prevent memory leaks.
*   **Generic Lambdas**: use `auto` parameters in lambdas to iterate over directories cleanly.
*   `std::shared_timed_mutex`: use this so multiple threads can read telemetry data at the same time without blocking, while keeping it locked when the engine writes new data.
*   `std::filesystem`: use this to navigate the Linux directory structure instead of older C style calls.
*   `std::string_view`: use this to parse text from Linux system files without copying strings or allocating new memory.
*   `std::optional`: return this instead of null values when a file is missing or locked, forcing me to handle missing data safely.