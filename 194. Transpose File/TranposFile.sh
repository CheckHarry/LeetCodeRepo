awk 'BEGIN{x[1] = "";d}{d = split($0 , array , " ");for(i = 1 ; i <= d ; i ++){if(x[i]==""){x[i] = array[i]}else{x[i] = x[i]" "array[i]}}}END{for(i = 1 ; i <= d ; i ++){print x[i]}}' file.txt
