#include <iostream>
#include <vector>
#include <vulkan/vulkan.h>

int main(int argc, char ** argv)
{
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "vkHelloWorld";
    appInfo.applicationVersion = 1;
    appInfo.apiVersion = VK_MAKE_VERSION(1, 0, 0);

  
    VkInstanceCreateInfo ici = {};
    ici.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    ici.pApplicationInfo = &appInfo;

    VkInstance vkInstance{};
    if (VK_SUCCESS != vkCreateInstance(&ici, nullptr, &vkInstance)) {
        std::cerr << "Unable to create Vulkan instance" << std::endl;
        return -1;
    }
    std::clog << "Succesfully created Vulkan instance : " << vkInstance << std::endl;

    uint32_t physicalDeviceCount = 0;
    vkEnumeratePhysicalDevices(vkInstance, &physicalDeviceCount, nullptr);

    std::vector<VkPhysicalDevice> physicalDevices(physicalDeviceCount);
    vkEnumeratePhysicalDevices(vkInstance, &physicalDeviceCount, physicalDevices.data());

    std::clog << "Number of phyisical devices : " << physicalDeviceCount << std::endl;
    std::clog << std::endl;

    for (const auto & device : physicalDevices)
    {
        VkPhysicalDeviceProperties deviceProp = {};
        vkGetPhysicalDeviceProperties(device, &deviceProp);

        std::clog << "apiVersion = " << deviceProp.apiVersion << std::endl;
        std::clog << "driverVersion = " << deviceProp.driverVersion << std::endl;
        std::clog << "vendorID = " << deviceProp.vendorID << std::endl;
        std::clog << "deviceID = " << deviceProp.deviceID << std::endl;
        std::clog << "deviceType = " << deviceProp.deviceType << std::endl;
        std::clog << "deviceName = " << deviceProp.deviceName << std::endl;
        std::clog << std::endl;
    }

    return 0;
}
