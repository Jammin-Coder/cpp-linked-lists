import subprocess
import time
import argparse

def get_command_list():
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", "--command", dest="cmd", help="Command to execute.")
    args = parser.parse_args()
    
    if not args.cmd:
        parser.error("No command specified! Specify a command with -c")
    return args.cmd.split(" ")
    
    
command_list = get_command_list()

start = time.time()

subprocess.call(command_list);

end = time.time();

print("[+] Finished in " + str(round(end - start, 3)) + " seconds.")

