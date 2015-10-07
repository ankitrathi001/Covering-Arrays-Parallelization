#!/bin/bash
rm Output_1207543476
export OMP_NUM_THREADS=16
echo "export OMP_NUM_THREADS=16"
#sbatch -N1 -n16 --mem-per-cpu=100m -t00:05:00 --qos=test run.sh
echo "#SBATCH -N1 -n16 --mem-per-cpu=100m -t00:05:00 --qos=test"
cd /home/arathi3/CSE430_P1
gcc -o P1_ANKIT_RATHI_SERIAL P1_ANKIT_RATHI_SERIAL.c -lm
gcc -o P1_ANKIT_RATHI_PARALLEL P1_ANKIT_RATHI_PARALLEL.c -fopenmp -lm
echo "Results from Serial and Parallel code:"
./P1_ANKIT_RATHI_SERIAL < testfile1
./P1_ANKIT_RATHI_PARALLEL < testfile1
./P1_ANKIT_RATHI_SERIAL < testfile2
./P1_ANKIT_RATHI_PARALLEL < testfile2
./P1_ANKIT_RATHI_SERIAL < testfile3
./P1_ANKIT_RATHI_PARALLEL < testfile3
./P1_ANKIT_RATHI_SERIAL < testfile4
./P1_ANKIT_RATHI_PARALLEL < testfile4
./P1_ANKIT_RATHI_SERIAL < testfile5
./P1_ANKIT_RATHI_PARALLEL < testfile5
./P1_ANKIT_RATHI_SERIAL < testfile6
./P1_ANKIT_RATHI_PARALLEL < testfile6
./P1_ANKIT_RATHI_SERIAL < testfile7
./P1_ANKIT_RATHI_PARALLEL < testfile7
./P1_ANKIT_RATHI_SERIAL < testfile8
./P1_ANKIT_RATHI_PARALLEL < testfile8
./P1_ANKIT_RATHI_SERIAL < testfile9
./P1_ANKIT_RATHI_PARALLEL < testfile9
./P1_ANKIT_RATHI_SERIAL < testfile10
./P1_ANKIT_RATHI_PARALLEL < testfile10
./P1_ANKIT_RATHI_SERIAL < testfile11
./P1_ANKIT_RATHI_PARALLEL < testfile11
./P1_ANKIT_RATHI_SERIAL < testfile12
./P1_ANKIT_RATHI_PARALLEL < testfile12
./P1_ANKIT_RATHI_SERIAL < testfile13
./P1_ANKIT_RATHI_PARALLEL < testfile13
./P1_ANKIT_RATHI_SERIAL < testfile14
./P1_ANKIT_RATHI_PARALLEL < testfile14
./P1_ANKIT_RATHI_SERIAL < testfile15
./P1_ANKIT_RATHI_PARALLEL < testfile15
./P1_ANKIT_RATHI_SERIAL < testfile16
./P1_ANKIT_RATHI_PARALLEL < testfile16
./P1_ANKIT_RATHI_SERIAL < testfile17
./P1_ANKIT_RATHI_PARALLEL < testfile17
echo "Done experiment"
