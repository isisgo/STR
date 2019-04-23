
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <unistd.h>



int main(int argc, char *argv[]) {

  // We want to camp on the 2nd CPU. The ID of that core is #1.
  const int core_id = 0;
  const pid_t pid = getpid();

  // cpu_set_t: This data set is a bitset where each bit represents a CPU.
  cpu_set_t cpuset;
  // CPU_ZERO: This macro initializes the CPU set set to be the empty set.
  CPU_ZERO(&cpuset);
  // CPU_SET: This macro adds cpu to the CPU set set.
  CPU_SET(core_id, &cpuset);

  // sched_setaffinity: This function installs the cpusetsize bytes long affinity mask pointed to by cpuset for the process or thread with the ID pid. If successful the function returns zero and the scheduler will in future take the affinity information into account.
  const int set_result = sched_setaffinity(pid, sizeof(cpu_set_t), &cpuset);


  // Check what is the actual affinity mask that was assigned to the thread.

  // sched_getaffinity: This functions stores the CPU affinity mask for the process or thread with the ID pid in the cpusetsize bytes long bitmap pointed to by cpuset. If successful, the function always initializes all bits in the cpu_set_t object and returns zero.
  const int get_affinity = sched_getaffinity(pid, sizeof(cpu_set_t), &cpuset);

  // CPU_ISSET: This macro returns a nonzero value (true) if cpu is a member of the CPU set set, and zero (false) otherwise.
  if (CPU_ISSET(core_id, &cpuset)) {

    fprintf(stdout, "Successfully set thread %d to affinity to CPU %d\n", pid, core_id);
  } else {

    fprintf(stderr, "Failed to set thread %d to affinity to CPU %d\n", pid, core_id);
  }
          while(true){
                    printf("1\n");
          }
  return 0;
}
