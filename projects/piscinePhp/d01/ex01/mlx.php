<?php
$line_limit = 100;
$count = 1;
while($count <= 1000)
{
    if(!($count++ % $line_limit))
        print("\n");
    else
        print("X");
}
