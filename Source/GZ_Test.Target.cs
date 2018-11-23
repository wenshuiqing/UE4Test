// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class GZ_TestTarget : TargetRules
{
	public GZ_TestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "GZ_Test" } );
	}

    //public override void SetupBinaries(TargetInfo Target,ref List<UEBuildBinaryConfiguration> OutBuildBinaryConigurations,
    //    ref List<string> OutExtraModuleNames)
    //{
    //    OutExtraModuleNames.AddRange(new string[]
    //    {
    //        "TestModule"
    //    });
    //}
}
