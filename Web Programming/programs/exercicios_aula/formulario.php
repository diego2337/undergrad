<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Formulario exercício 1</title>
        <style>
            fieldset{
                width: 400px;
                margin: 0 auto;
            }
            
            .campos{
                
            }
            
            .input{
                margin: 0 0 10px 0;
                //float: left;
            }
            
            .botoes{
                float: right;
            }
        </style>
    </head>
    <body>
        <fieldset>
            <legend>Dados</legend>
            <form action="processa.php" method="POST">
                <div class="campos">
                    <div class="input">
                        <label>Nome:</label><input type="text" name="nome" />
                    </div>
                    <div class="input">
                        <label>Salário:</label><input type="number" name="salario" />
                    </div>
                    <div class="botoes">
                        <input type="submit" value="Gravar"/>
                    </div>
                </div>


            </form>
        </fieldset>
    </body>
</html>


