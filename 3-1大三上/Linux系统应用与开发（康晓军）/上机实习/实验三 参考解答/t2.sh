read -p "Input your score: " score
if (( $score >= 0 && $score < 60  ))
then
        echo 'Failed!'
elif (( $score >= 60 && $score < 70 ))
then
        echo 'Passed!'
elif (( $score >= 70 && $score < 80 ))
then
        echo 'Medium!'
elif (( $score >= 80 && $score < 90 ))
then
        echo 'Good!'
elif (( $score >= 90 && $score <= 100 ))
then
        echo 'Excellent!'
else
        echo 'Input error!'
fi