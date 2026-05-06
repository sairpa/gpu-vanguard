#include<iostream>
#include <webgpu/webgpu.h>


// Adapter acquisition
void wgpuInstanceRequestAdapter(
  WGPUInstance instance,
  WGPU_NULLABLE WGPURequestAdapterOptions const * options,
  WGPURequestAdapterCallback callback,
  void * userdata
){
  
}


int main(int, char**){

    std::cout<< "Web GPU fun starts here! :D\n";

    // Descriptor WGPU
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    // We create the instance using this descriptor
    #ifdef WEBGPU_BACKEND_EMSCRIPTEN
      WGPUInstance instance = wgpuCreateInstance(nullptr);
    #else //  WEBGPU_BACKEND_EMSCRIPTEN
      WGPUInstance instance = wgpuCreateInstance(&desc);
    #endif //  WEBGPU_BACKEND_EMSCRIPTEN

    // Check for instance creation
    if (!instance){
        std::cerr << "WebGPU intialisazation failed!\n";
        return -1;
    }

    // WGPU instance simple pointer
    std::cout << "WebGPU instance: " << instance << "\n";

    // We clean up the WebGPU instance
	  wgpuInstanceRelease(instance);
    
    return 0;

}

