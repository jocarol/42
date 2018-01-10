#!/usr/bin/php
<?PHP

unset($argv[0]);
foreach($argv as $arg)
{
    $tmp = array_filter(explode(' ', $arg));
    foreach ($tmp as $arg_to_sort)
        $array[] = $arg_to_sort;
    sort($array);
    foreach ($array as $elem)
        echo $elem."\n";
}
?>