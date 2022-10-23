#!/bin/sh

cur_dir=$PWD
root_dir=$(cd $cur_dir"/../"; pwd)
temp_contest_dir=$(cd $cur_dir"/../template/contest"; pwd)

contest_web_brief=$1
contest_name=$2
# mkdir

if [ $contest_web_brief == "cf" ]
then 
    contest_web="codeforces"
elif [ $contest_web_brief == "atc" ]
then
    contest_web="atcoder"
fi

echo $contest_web
echo $root_dir