%%
[a-zA-Z_][a-zA-Z0-9_]* { return Token::IDENTIFIER; }
-?[0-9]+ { return Token::NUMBER; }
==           { return Token::EQUAL_OPERATOR; }
!=           { return Token::NOT_EQUAL_OPERATOR; }
<=           { return Token::LESS_EQUAL_OPERATOR; }
>=           { return Token::GREATER_EQUAL_OPERATOR; }
&&           { return Token::AND_OPERATOR; }
\|\|         { return Token::OR_OPERATOR; }
\+           { return Token::SUM_OPERATOR; }
-            { return Token::SUBTRACTION_OPERATOR; }
\*           { return Token::MULTIPLICATION_OPERATOR; }
\/           { return Token::DIVISION_OPERATOR; }
%            { return Token::MODULE_OPERATOR; }
<            { return Token::LESS_OPERATOR; }
>            { return Token::GREATER_OPERATOR; }
!            { return Token::NOT_OPERATOR; }
=            { return Token::ASSIGN_OPERATOR; }
;            { return Token::SEMICOLON; }
,            { return Token::COMA; }
\(           { return Token::LEFT_PAR; }
\)           { return Token::RIGHT_PAR; }
\{           { return Token::LEFT_KEY; }
\}           { return Token::RIGHT_KEY; }
\[[^\]]*\]   { return Token::BRACKET_IDENT}
\/\*([^(\*\/)]|\*)*\*\/  {return Token::COMMENTBLOCK}
[ \t\n\r]+   { /* Ignorar el token (espacio en blanco) */ }
\/\/[^\n]* { /* Ignorar el token (Comentario)*/ }
<<EOF>>      { return Token::END_OF_FILE; }
%%