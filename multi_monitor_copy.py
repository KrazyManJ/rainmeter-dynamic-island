import os
import shutil

COPY_NUMBERS = 2

script_path = os.path.dirname(os.path.abspath(__file__))

multi_monitor_dir = os.path.join(script_path, "Multi-Monitor")
if os.path.exists(multi_monitor_dir):
    shutil.rmtree(multi_monitor_dir)
os.makedirs(multi_monitor_dir, exist_ok=True)

for i in range(COPY_NUMBERS):
    monitor_dir = os.path.join(multi_monitor_dir, f"Monitor-{i+2}")
    os.makedirs(monitor_dir, exist_ok=True)
    
    files_to_copy = [filename for filename in os.listdir(script_path) if filename.startswith("DI_")]
    
    for filename in files_to_copy:
        src_path = os.path.join(script_path, filename)
        dest_path = os.path.join(monitor_dir, filename)
        
        lines = open(src_path,"r").readlines()
        lines.insert(8,f"    ContextAction5=[!Move (#SCREENAREAX@{i+2}#+#SCREENAREAWIDTH@{i+2}#/2-#C_SKIN_WIDTH#/2-#C_SKIN_MARGIN#) 0]\n")
        open(dest_path,"w").write("".join(lines))
        
