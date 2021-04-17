package com.example.burshTopic;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.util.*;

@SpringBootApplication
public class BurshTopicApplication {
	public static void main(String[] args) {

		int[] arrayA = new int[]{2, 3, 6,7};//静态数组标准分配
		List<List<Integer>> list = combinationSumStart(arrayA,7);
		System.out.println(list);
		SpringApplication.run(BurshTopicApplication.class, args);
	}

	public static List<List<Integer>> combinationSumStart(int[] candidates, int target) {
		List<List<Integer>> res =  new ArrayList<>();
		if (candidates.length <= 0) {
			return res;
		}
		// 排序
		Arrays.sort(candidates);
		Integer len = candidates.length;
		Deque<Integer> nodePath = new ArrayDeque<>();
		compute(candidates,target,res,nodePath,0);
		return res;
	}

	private static void compute(int[] candidates, int target, List<List<Integer>> res,Deque<Integer> nodePath, int begin)  {
		System.out.print("进入递归");
		if (target == 0) {
			res.add(new ArrayList<>(nodePath));
			return;
		}
		if (target < 0) {
			return;
		}
		for (int i = begin;i < candidates.length;i++) {
			int subTarget = target - candidates[i];
			if (subTarget < 0) {
				break;
			}
			nodePath.addLast(candidates[i]);
			compute(candidates,subTarget,res,nodePath,i);
			nodePath.removeLast();
		}
	}
}
