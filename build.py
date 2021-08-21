import os
import shutil
import subprocess

cmakePath = shutil.which("cmake")

def runCmd(cmd):
    print(f"Running command: {cmd}")
    try:
        subprocess.run(cmd)
    except Exception as err:
        print(f"Failed to run cmd: '{cmd}' with error: '{err}'.")


def makeDir(dir):
    try:
        os.makedirs(dir, 0o755, exist_ok=True)
    except OSError:
        print(f"Failed to create dir: {dir}")
    else:
        print(f"Created dir: {dir}")


def buildNodes():
    print("Building nodes...")

    buildDir = os.path.join(os.getcwd(), "src", "build")
    makeDir(buildDir)

    os.chdir(buildDir)

    cmd = [cmakePath, ".."]
    runCmd(cmd)

    cmd = [cmakePath, "--build", "."]
    runCmd(cmd)

    print("Built nodes.")


print("Building...")

buildNodes()

print("Built.")
