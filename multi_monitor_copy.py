import os
import shutil

COPY_NUMBERS = 2
SCRIPT_PATH = os.path.dirname(os.path.abspath(__file__))
MULTI_MONITOR_DIR = os.path.join(SCRIPT_PATH, "Multi-Monitor")

if os.path.exists(MULTI_MONITOR_DIR):
    shutil.rmtree(MULTI_MONITOR_DIR)
os.makedirs(MULTI_MONITOR_DIR, exist_ok=True)

for i in range(COPY_NUMBERS):
    monitor_dir = os.path.join(MULTI_MONITOR_DIR, f"Monitor-{i+2}")
    os.makedirs(monitor_dir, exist_ok=True)
    
    files_to_copy = [filename for filename in os.listdir(SCRIPT_PATH) if filename.startswith("DI_")]
    
    for filename in files_to_copy:
        src_path = os.path.join(SCRIPT_PATH, filename)
        dest_path = os.path.join(monitor_dir, filename)
        
        lines = open(src_path,"r").readlines()
        lines.insert(8,f"    ContextAction5=[!Move (#SCREENAREAX@{i+2}#+#SCREENAREAWIDTH@{i+2}#/2-#C_SKIN_WIDTH#/2-#C_SKIN_MARGIN#) 0]\n")
        open(dest_path,"w").write("".join(lines))
        
