namespace nsCessna
{
	/*A função yaw (guinada) foi escrita para contornar um fato do procedimento Glut para a função de utilização do mouse,
	a função será chamada por clique ou desclique mas não para enquanto ele for pressionado.
	Para compensar este movimento Yaw foi escrita como o retorno de uma chamada ociosa para que enquanto
	o botão do mouse é pressionado o avião vai permanece nessa guinada. É por isso que o retorno da chamada ociosa é uma chamada para yaw.
	*/




	void yaw(void)
	{
		turnspeed = (theta[2] / 10); // define a velocidade em que o avião irá virar

		if ((yaw0 == 1) && (planeyaw < 5)){ // faz um giro de 5 graus
			planeyaw++;
		}
		if ((yaw1 == 1) && (planeyaw > -5)){ // faz um giro de -5 graus
			planeyaw--;
		}

		if ((yaw0 == 0) && (yaw1 == 0) && (planeyaw > 0)){  // gira o avião de volta para a posição a frente enquanto
			planeyaw--;
			theta[1]--;// rotaciona
		}
		if ((yaw0 == 0) && (yaw1 == 0) && (planeyaw < 0)){
			planeyaw++;
			theta[1]++;
		}

		theta[1] = theta[1] + turnspeed; // gira de acordo com a velocidade

		if (yaw0 == 1) theta[1] -= 1.0; // se o botão está acionado, rotaciona
		if (yaw1 == 1) theta[1] += 1.0;

		propspin += propvar;  // a velocidade da helice pode ser mudada por com os botõs + e -
		if (propspin > 360.0) propspin -= 360.0;
		if (propspin < -360.0) propspin += 360.0;
		if (theta[1] > 180.0) theta[1] -= 360.0;
		if (theta[1] < -180.0) theta[1] += 360.0;
		speed = (propvar / 5.0);  // define a velocidade do avião pela variável de giro da helice


		// O código a seguir irá definit a movimentação perante o plano
		//alterando a posição nos eixos Z e X. A rotação  na direcção y foi definido para ser feito com funções de seno e cosseno
		//O movimento foi dividido em grupos de 10 graus para dar um movimento realista

		if ((theta[1] <= 0) && (theta[1] >= -10)){
			forwardpos += 1 * speed;
			sidewayspos -= 0;
		}
		if ((theta[1] < -10) && (theta[1] >= -20)){
			forwardpos += 0.92 * speed;
			sidewayspos -= 0.12 * speed;
		}
		if ((theta[1] < -20) && (theta[1] >= -30)){
			forwardpos += 0.75 * speed;
			sidewayspos -= 0.25 * speed;
		}
		if ((theta[1] < -30) && (theta[1] >= -40)){
			forwardpos += 0.62 * speed;
			sidewayspos -= 0.38 * speed;
		}
		if ((theta[1] < -40) && (theta[1] >= -50)){
			forwardpos += 0.5 * speed;
			sidewayspos -= 0.5 * speed;
		}
		if ((theta[1] < -50) && (theta[1] >= -60)){
			forwardpos += 0.38 * speed;
			sidewayspos -= 0.62 * speed;
		}
		if ((theta[1] < -60) && (theta[1] >= -70)){
			forwardpos += 0.25 * speed;
			sidewayspos -= 0.75 * speed;
		}
		if ((theta[1] < -70) && (theta[1] >= -80)){
			forwardpos += 0.12 * speed;
			sidewayspos -= 0.92 * speed;
		}
		if ((theta[1] < -80) && (theta[1] >= -90)){
			forwardpos += 0.0 * speed;
			sidewayspos -= 1.0 * speed;
		}
		if ((theta[1] < -90) && (theta[1] >= -100)){
			forwardpos -= 0 * speed;
			sidewayspos -= 1 * speed;
		}
		if ((theta[1] < -100) && (theta[1] >= -110)){
			forwardpos -= .12 * speed;
			sidewayspos -= .92 * speed;
		}
		if ((theta[1] < -110) && (theta[1] >= -120)){
			forwardpos -= .20 * speed;
			sidewayspos -= .83 * speed;
		}

		if ((theta[1] < -120) && (theta[1] >= -130)){
			forwardpos -= .25 * speed;
			sidewayspos -= .75 * speed;
		}
		if ((theta[1] < -130) && (theta[1] >= -140)){
			forwardpos -= .38 * speed;
			sidewayspos -= .62 * speed;
		}
		if ((theta[1] < -140) && (theta[1] >= -150)){
			forwardpos -= .5 * speed;
			sidewayspos -= .5 * speed;
		}
		if ((theta[1] < -150) && (theta[1] >= -160)){
			forwardpos -= .62 * speed;
			sidewayspos -= .38 * speed;
		}
		if ((theta[1] < -160) && (theta[1] >= -170)){
			forwardpos -= .75 * speed;
			sidewayspos -= .25 * speed;
		}
		if ((theta[1] < -170) && (theta[1] >= -175)){
			forwardpos -= .92 * speed;
			sidewayspos -= .18 * speed;
		}
		if ((theta[1] < -175) && (theta[1] >= -180)){
			forwardpos -= 1 * speed;
			sidewayspos -= 0;
		}

		if ((theta[1] >= 0) && (theta[1] <= 10)){
			forwardpos += 1 * speed;
			sidewayspos += 0;
		}
		if ((theta[1] > 10) && (theta[1] <= 20)){
			forwardpos += 0.92 * speed;
			sidewayspos += 0.12 * speed;
		}
		if ((theta[1] > 20) && (theta[1] <= 30)){
			forwardpos += 0.75 * speed;
			sidewayspos += 0.25 * speed;
		}
		if ((theta[1] > 30) && (theta[1] <= 40)){
			forwardpos += 0.62 * speed;
			sidewayspos += 0.38 * speed;
		}
		if ((theta[1] > 40) && (theta[1] <= 50)){
			forwardpos += 0.5 * speed;
			sidewayspos += 0.5 * speed;
		}
		if ((theta[1] > 50) && (theta[1] <= 60)){
			forwardpos += 0.38 * speed;
			sidewayspos += 0.62 * speed;
		}
		if ((theta[1] > 60) && (theta[1] <= 70)){
			forwardpos += 0.25 * speed;
			sidewayspos += 0.75 * speed;
		}
		if ((theta[1] > 70) && (theta[1] <= 80)){
			forwardpos += 0.12 * speed;
			sidewayspos += 0.92 * speed;
		}
		if ((theta[1] > 80) && (theta[1] <= 90)){
			forwardpos += 0.0 * speed;
			sidewayspos += 1.0 * speed;
		}
		if ((theta[1] > 90) && (theta[1] <= 100)){
			forwardpos -= 0 * speed;
			sidewayspos += 1 * speed;
		}
		if ((theta[1] > 100) && (theta[1] <= 110)){
			forwardpos -= .12 * speed;
			sidewayspos += .92 * speed;
		}
		if ((theta[1] > 110) && (theta[1] <= 120)){
			forwardpos -= .20 * speed;
			sidewayspos += .83 * speed;
		}

		if ((theta[1] > 120) && (theta[1] <= 130)){
			forwardpos -= .25 * speed;
			sidewayspos += .75 * speed;
		}
		if ((theta[1] > 130) && (theta[1] <= 140)){
			forwardpos -= .38 * speed;
			sidewayspos += .62 * speed;
		}
		if ((theta[1] > 140) && (theta[1] <= 150)){
			forwardpos -= .5 * speed;
			sidewayspos += .5 * speed;
		}
		if ((theta[1] > 150) && (theta[1] <= 160)){
			forwardpos -= .62 * speed;
			sidewayspos += .38 * speed;
		}
		if ((theta[1] > 160) && (theta[1] <= 170)){
			forwardpos -= .75 * speed;
			sidewayspos += .25 * speed;
		}
		if ((theta[1] > 170) && (theta[1] <= 175)){
			forwardpos -= .92 * speed;
			sidewayspos += .18 * speed;
		}
		if ((theta[1] > 175) && (theta[1] <= 180)){
			forwardpos -= 1 * speed;
			sidewayspos += 0 * speed;
		}

		glutPostRedisplay();
	}

	void stallanimate(){ // chamado quando o avião para
		updownspeed -= 2; // faz com que ele perca altitude
		theta[0] += 4; // e inicie um mergulho
	}
}

