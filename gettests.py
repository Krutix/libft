import sys
import subprocess
import os

def get_all_tests(files):
    pattern = '-G \'^TEST(.*)$\''
    cmd = f'grep {pattern} -h {" ".join(str(file) for file in files)}'
    output = subprocess.check_output(cmd, shell=True)
    s = str(output).strip("'b\\n").split("\\n")
    return s


ftst_test_runner = open('ftst_test_runner.c', 'w')

ftst_test_runner.write("#include \"ftst.h\"\n")
ftst_test_runner.write("\n")

tests = get_all_tests(sys.argv[1::])
for test in tests:
    ftst_test_runner.write(f"{test};\n")

ftst_test_runner.write("\n")
ftst_test_runner.write("int main()\n")
ftst_test_runner.write("{\n")
ftst_test_runner.write("\tFTST_INIT();\n")
ftst_test_runner.write("\n")

for test in tests:
    ftst_test_runner.write(f"\t{test.replace('TEST', 'RUNTEST')};\n")

ftst_test_runner.write("\n")
ftst_test_runner.write("\tFTST_EXIT();\n")
ftst_test_runner.write("}\n")
