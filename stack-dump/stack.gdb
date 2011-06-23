thread apply all bt full
set print address on

break 8
run

echo \n
echo Backtrace\n
echo =========\n\n
bt

echo \n
echo Frames\n
echo ======\n\n
info frame 0
info frame 1

echo \n
echo Stack Hexdump\n
echo =============\n\n
x print_log
x/64xw $sp
disassemble ffi_call_unix64
quit
