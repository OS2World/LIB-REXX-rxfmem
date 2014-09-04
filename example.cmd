/* Example of using RxFreeMem() function */
call RxFuncAdd 'RxFreeMem','RxFMem','RxFreeMem'

freephysical=RxFreeMem('Physical')
freevirtual=RxFreeMem('Virtual')

say ''
say 'Free physical memory: '||freephysical
say ''
say 'Free virtual memory: '||freevirtual
