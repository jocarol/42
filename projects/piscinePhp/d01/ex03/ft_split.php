<?php
    function ft_split($str_to_split)
    {
        $ret = array_filter(explode(' ', $str_to_split));
        sort($ret);
        return ($ret);
    }
?>