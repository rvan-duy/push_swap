sum=0
a=499
n=20

for i in `seq 1 $n`
do
    arguments=`ruby -e "puts (0..$a).to_a.shuffle.join(' ')"`
    result=$(./push_swap $arguments | ./checker $arguments)
    wc=$(./push_swap $arguments | wc -l)
    sum=$((sum + wc))
    if [ "$result" == "OK" ]; then
        printf "\033[32mtest $i passed\033[0m - operation count: $wc\n";
    else
        printf "TEST FAILED\n$arguments\n";
        exit 1;
    fi
done

avg=$(echo $sum / $n | bc -l)

printf "average: $avg\n"