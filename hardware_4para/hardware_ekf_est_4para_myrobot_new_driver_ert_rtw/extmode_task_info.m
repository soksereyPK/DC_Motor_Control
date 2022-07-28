function [taskInfo, numtask, isDeploymentDiagram]=extmode_task_info()


      taskInfo(1).samplePeriod = 0.0;
      taskInfo(1).sampleOffset = 0.0;

        taskInfo(1).taskPrio = 40;

        taskInfo(1).taskName = 'BaseRate';
      taskInfo(1).entryPoints = {};
    

      taskInfo(2).samplePeriod = 0.01;
      taskInfo(2).sampleOffset = 0.0;

        taskInfo(2).taskPrio = 40;

        taskInfo(2).taskName = ['SubRate' '1'];        
      taskInfo(2).entryPoints = {};
    




  numtask = 2;
  for i = 1:numtask
    if ( 0 == isnumeric(taskInfo(i).samplePeriod) )
      taskInfo(i).samplePeriod = evalin('base', 'str2double(taskInfo(i).samplePeriod)');
    end
    if ( isempty(taskInfo(i).taskName) )
      taskInfo(i).taskName = ['AutoGen' i ];
    end
  end

  isDeploymentDiagram = 0;

end 
