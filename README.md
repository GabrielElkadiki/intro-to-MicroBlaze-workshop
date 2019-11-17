# intro-to-MicroBlaze-workshop
IEEE Carleton Intro to MicroBlaze workshop: In this workshop, you will be setting up and programming a MicroBlaze Design and then attaching it to your own Verilog Hardware.  

** For Vivado 2016.3 **

How to run '.tcl' scripts in Vivado:

Launch Vivado open the tcl console below
Navigate to the tcl console and type in'cd "Your Project Directory" to navigate to the script path
Then type in: source build.tcl
Note: Ensure the script is not located in a directory with a space in it

(i.e C:/Users/Gabriel Elkadiki/project)

To build this project:
1. Create a new project in Vivado
2. Ensure all required IP's are in the catalog
2. Build the block diagrams using the steps above
3. Update all IPs by typing this into the TCL console: upgrade_ips [get_ips]
4. Generate a new bitstream and Export Hardware to SDK (Tick Include bitstream)
5. Program the board using the hardware manager and select the bitstream.
6. Launch the SDK and create a new application project -> Empty Project
7. Copy the C program in the SDK folder, select the USB port the FPGA is connected to and then program the MicroBlaze.

Steps on building the project yourself can be found here:
[IEEE Carleton Intro To MicroBlaze Workshop 2019](https://docs.google.com/presentation/d/1hfE7lqGiGhEzx4Mnj9NXa4FJq4tLA_tECX6K2kmoFtk/edit?usp=sharing)
