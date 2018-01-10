#!/usr/bin/php
<?PHP

if ($argc == 2)
{
    $array = array_filter(explode(" ", $argv[1]));
    $res = "";
    foreach ($array as $word)
        $res .= $word." ";
    fwrite(STDOUT, $res);
    echo "\n";
}

?>