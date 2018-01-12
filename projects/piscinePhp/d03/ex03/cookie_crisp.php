<?php
if (isset($_GET['action']))
{
    if (isset($_GET['name']))
    {
        if ($_GET['action'] == 'set')
            setcookie($_GET['name'], $_GET['value'], time()+3600);
        elseif ($_GET['action'] == 'get')
            echo $_COOKIE[$_GET['name']];
        elseif ($_GET['action'] == 'del')
            setcookie($_GET['name'], '', -1);
    }
}
?>