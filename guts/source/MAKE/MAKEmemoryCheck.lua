function MAKEmemoryCheck()
   OSexecute("cd ~/flow/guts/source/ && make clean && make memcheck -j16");
end
