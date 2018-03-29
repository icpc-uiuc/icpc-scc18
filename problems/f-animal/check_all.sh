for fn in tests/*.in; do
    echo "$fn"; 
    python3 check.py < "$fn"
done
