## Pthreads parte 2  
  
a) Na solução utilizando Mutex, o que mudou é que agora uma única thread tem acesso exclusivo para atualizar o valor total resultante das somas parciais de cada thread. Isso é assegurado pela exclusividade de acesso garantida pelo Mutex, que bloqueia outras threads de acessar a variável global 'pi' enquanto uma thread estiver realizando a atualização.  
  
b) Os valores atingidos nao houveram divergencias.
