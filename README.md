# linked-lists
An assignment for Concurrent Programming class on implementing linked lists with concurrent access

To compile this project, you need to have CMake 3.4 or higher installed. To install CMake, follow the following instructions:
```
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:george-edison55/cmake-3.x
sudo apt-get update
sudo apt-get install cmake
```
To compile and build the project, navigate to the root of the project directory and create a directory for the build named "build". 
Navigate to this build directory and enter the following commands:
```
cmake ..
make
```
If the build was successful, it will have created an executable file named "linked_lists" in the build directory.
To run the program, pass the following arguments: no_threads, no_insert_ops, no_delete_ops, no_member_ops

i.e: ```linked_lists 4 0.05 0.05 0.9```
