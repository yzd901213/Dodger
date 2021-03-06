mkdir $2
rm $2*.png

OUTPUT_JSON=$1$4.json
OUTPUT_AVI=$3$4.avi

echo Running search
bin/$4 > $OUTPUT_JSON

echo Running animator
python scripts/run_animator.py $OUTPUT_JSON $2

echo Creating video
mencoder mf://$2*.png -mf w=800:h=600:fps=11:type=png -ovc lavc \
    -lavcopts vcodec=mpeg4:mbd=2:trell -oac copy -o $OUTPUT_AVI
